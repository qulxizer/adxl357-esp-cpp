{
  inputs = {
    nixpkgs-esp-dev = {
      url = "github:mirrexagon/nixpkgs-esp-dev";
    };
  };
  outputs =
    {
      self,
      nixpkgs,
      nixpkgs-esp-dev,
    }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
        overlays = [ (import "${nixpkgs-esp-dev}/overlay.nix") ];
        config.permittedInsecurePackages = [
          "python3.14-ecdsa-0.19.2"
        ];
      };

      # change esp-idf-esp32 to whatever is the toolchain you're using
      idf = nixpkgs-esp-dev.packages.${system}.esp-idf-xtensa.override (final: {
        toolsToInclude = final.toolsToInclude ++ [
          "esp-clang"
        ];
      });
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        buildInputs = with pkgs; [
          idf
        ];

        # passed as --query-driver=$CLANGD_QUERY_DRIVER to clangd
        shellHook = ''
          export CLANGD_QUERY_DRIVER=`which xtensa-esp32-elf-g++`
        '';
      };
    };
}

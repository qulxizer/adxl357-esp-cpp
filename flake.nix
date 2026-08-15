{
  description = "ESP dev shell";

  inputs = {
    nixpkgs-esp-dev.url = "github:mirrexagon/nixpkgs-esp-dev";
    nixpkgs.follows = "nixpkgs-esp-dev/nixpkgs";
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
          "python3.13-ecdsa-0.19.1"
        ];
      };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        name = "adxl357";
        buildInputs = with pkgs; [
          esp-idf-full
        ];
      };
    };
}

{ pkgs ? import <nixpkgs> {} }:

with pkgs;

mkShell {
  nativeBuildInputs = [
    gcc
    gnumake
    cmake
    cmake-format
    clang-tools
    # ccls
    jetbrains.clion
  ];
  buildInputs = [
    sfml
  ];
}

with import <nixpkgs> { };
with pkgs;

stdenv.mkDerivation {
  name = "AntSimulator";
  version = "dev";
  src = lib.cleanSource ./.;

  nativeBuildInputs = [
    cmake
  ];

  buildInputs = [
    sfml
  ];

  preBuild = ''
    cmake .
  '';

  buildPhase = ''
   make debug
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp AntSimulator $out/bin/
    cp compile_commands.json $out/
  '';

  enableParallelBuilding = true;
}

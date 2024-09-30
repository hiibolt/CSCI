{
    description = "G++ compiler with C++14 standard";
    inputs = {
        nixpkgs.url = github:NixOS/nixpkgs;
        flake-utils.url = github:numtide/flake-utils;
    };
    outputs = { self, nixpkgs, flake-utils }: 
        flake-utils.lib.eachDefaultSystem (system:
            let
                pkgs = import nixpkgs { inherit system; };
            in
            {
                devShell = pkgs.mkShell { 
                    buildInputs = [ 
                        pkgs.gpp
                        pkgs.gdb
                    ];
                    shellHook = ''
                    echo C++!
                    '';
                    BUILD_COMMAND = "make";
                    TEST_COMMAND  = "make run";
                    CLEAN_COMMAND = "make clean";
                    DEBUG_COMMAND = "make debug";
                };
            });
}

# CSCI
Core repository in which I host my assignments for various computer science courses. Language varies.

## Development Environment

### Compilation
I use terse Nix Flakes with a terse `devShell`, with a flake differing based on the course or program.

I use [**direnv**](https://direnv.net/) to automatically load said flake as my environment, which also hot-reloads the environment if I tweak `flake.nix`.

I try to use industry standard for both choice of compiler and compilation options, where possible.

### Shell
I use [**fish**](https://fishshell.com/) with [**tide**](https://github.com/IlanCosman/tide) for pretty output.

I have a few different custom commands for quickly typing compilation instructions, so I have provided my `config.fish` file below for your convenience.

**Config:**
```fish
set -x DIRENV_LOG_FORMAT ""
eval (direnv hook fish)
function c
    set_color -o red
    echo "Cleanup phase '$CLEAN_COMMAND'"
    set_color normal
    eval "$CLEAN_COMMAND"
end
function b
    set_color -o yellow
    echo "Build phase '$BUILD_COMMAND'"
    set_color normal
    eval "$BUILD_COMMAND"
end
function t
    set_color -o green
    echo "Test phase '$TEST_COMMAND'"
    set_color normal
    eval "$TEST_COMMAND"
end
function d
    set_color -o blue
    echo "Debug phase '$DEBUG_COMMAND'"
    set_color normal
    eval "$DEBUG_COMMAND"
end
function cbt
    c
    b
    t
end
function e
    code . &
    disown
    exit
end
function cfg
    cd /etc/nixos
    xdg-open .
    code .
end
function boilerplate -d "Grabs a boilerplate from https://github.com/boltr6/nix-templates"
    if contains -- "$argv" "-L" "--list"
        # List the available boilerplates
        git clone -q https://github.com/boltr6/nix-templates
        echo "Availabe boilerplates:"
        ls "$PWD/nix-templates"
        rm -R -f nix-templates
    else
        # Clone and move the selected boilerplate
        git clone -q https://github.com/boltr6/nix-templates
        echo "Grabbing the following files:"
        ls -A "$PWD/nix-templates/$argv[1]"
        mv -n "$PWD/nix-templates/$argv[1]/"{.*,*} "$PWD"
        rm -R -f nix-templates
        echo "Done"
    end
end
set_color -i cyan
set fish_greeting "Don't stop 'till Stanford"
```

### Editor
I use [**VSCode from unstable@nixpkgs**](https://search.nixos.org/packages?channel=23.11&show=vscode&from=0&size=50&sort=relevance&type=packages&query=vscode).

Extensions:
- Discord Rich Presence
- Remote - SSH
- Remote Explorer
- Nix
- Nix Environment
- Even Better TOML

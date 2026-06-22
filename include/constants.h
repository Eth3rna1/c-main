#pragma once

const char* INCLUDE_DIR = "include";

const char* SRC_DIR = "src";

const char* TESTS_DIR = "tests";

const char* MAIN_C_LOC = "src/main.c";

const char* GITIGNORE_LOC = ".gitignore";

const char* GITIGNORE_CONTENT = "__pycache__\nmain.exe";

const char* BUILD_PY_LOC = "build.py";

const char* BUILD_PY_CONTENT = "\"\"\"\nCompilation process for C codebase\n\"\"\"\n\nimport os\nimport sys\nimport subprocess\n\n\nSRC_DIR = \"src\"\n\nEXE_NAME = \"main.exe\"\n\nFILES = [os.path.join(SRC_DIR, file) for file in os.listdir(SRC_DIR)]\n\n\nif \"-w\" in sys.argv:\n    subprocess.run(\n        [\n            \"gcc\",\n            *FILES,\n            \"-Wall\",\n            \"-Wextra\",\n            \"-o\",\n            EXE_NAME,\n        ]\n    )\nelse:\n    subprocess.run(\n        [\n            \"gcc\",\n            *FILES,\n            \"-o\",\n            EXE_NAME,\n        ]\n    )\n\n\nif \"-r\" in sys.argv:\n    subprocess.run([EXE_NAME])\n";

const char* MAIN_C_CONTENT = "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}\n";

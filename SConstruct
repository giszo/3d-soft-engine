env = Environment()

env["CXXFLAGS"] = ["-O2", "-Wall", "-std=c++11"]
env["CPPPATH"] = [Dir("src")]

sources = [
    "vector.cpp",
    "matrix.cpp",
    "window.cpp",
    "rasterizer.cpp",
    "mesh.cpp",
    "vertex.cpp"
]

tests = [
    "matrix.cpp"
]

engine_lib = env.SharedLibrary(
    "engine",
    source = ["src/%s" % s for s in sources]
)

env.Program(
    "3d-engine",
    source = ["src/main.cpp"] + engine_lib,
    LIBS = ["SDL"]
)

env.Program(
    "unit_test",
    source = ["tst/%s" % t for t in tests] + ["tst/main.cpp"] + engine_lib,
    LIBS = ["SDL", "boost_unit_test_framework"]
)

from setuptools import setup, Extension

module = Extension(
    "fastmath",
    sources=["fastmath.c"]
)

setup(
    name="fastmath",
    version="1.0",
    description="Example Python C extension",
    ext_modules=[module]
)

# python3 setup.py build_ext --inplace
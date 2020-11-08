from distutils.core import setup, Extension


# python setup.py build
# python setup.py install


module = Extension("myModule", sources = ["myModule.c"])

setup(name="PackageName", 
	version = "1.0", 
	description="This is a package for myModule",
	ext_modules = [module])

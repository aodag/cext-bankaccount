from setuptools import setup, find_packages, Extension


setup(
    name="cext-bankaccount",
    packages=find_packages(),
    ext_modules=[Extension('bankaccount', ['src/bankaccount.c'])],
)

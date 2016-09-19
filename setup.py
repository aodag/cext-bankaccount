import os
import re
from setuptools import setup, find_packages, Extension

here = os.path.dirname(__file__)


def read_version():
    with open(os.path.join(here, 'bankaccount', '__version__.py')) as f:
        m = re.match(r"version\s*=\s*\'(?P<version>[\d\.]*)\'", f.read())
        if m is None:
            return
        return m.groupdict()['version']


__version__ = read_version()

setup(
    name="cext-bankaccount",
    version=__version__,
    packages=find_packages(exclude=['tests']),
    ext_modules=[Extension('_bankaccount', ['src/bankaccount.c'])],
)

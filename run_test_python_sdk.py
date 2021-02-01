"""run all scenarios"""
import os

os.chdir("scenarios") # go to folder
os.system("pytest -vv") # run test

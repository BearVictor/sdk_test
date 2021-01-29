"""run all scenarios"""
import os

os.chdir("scenarios") # go to folder
list_dir = os.listdir() # take all folders in <scenarios>

for dir in list_dir:
    if "_" in dir: # if hidden folder
        continue # we miss it

    #TODO ignore
    os.chdir(dir) # go to folder
    os.system("pytest") # run test

    path_parent = os.path.dirname(os.getcwd()) #correctly path
    os.chdir(path_parent) # move directory upper
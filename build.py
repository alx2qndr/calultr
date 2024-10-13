import os
import subprocess

if not os.path.exists("build"):
    os.makedirs("build")

os.chdir("build")

subprocess.run(["cmake", ".."])
subprocess.run(["cmake", "--build", ".", "--config", "Release"])

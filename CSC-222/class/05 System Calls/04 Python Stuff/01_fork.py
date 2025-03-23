import os

print("Before Fork")

pid = os.fork()

print("Child and Parent")

if pid == 0:
    print(f"child {pid}")
else:
    print(f"parent {pid}\t{os.getpid()}")
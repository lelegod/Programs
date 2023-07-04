# let getfiles(dirname, files) be
#    let name be each entry within directory dirname
#        let path be dirname joined with name
#        if path is a directory
#            call getfiles(path, files)
#        else if path is a file
#            append path to files
#    return files
#
# let getsizes(paths) be
#    let sizes be an empty list
#    let  path be each element in the list paths
#        append the tuple (size of the file path, path) to the list sizes
#    return sizes
#
# let dirs be an empty list
#
# if there are no comment line arguments
#    append the current working directory to dirs
# else
#    extend dirs with the command line arguments
#
# let sizes be an empty list
#
# let dirname be each element int he list dirs
#    let files be an empty list
#    let paths be the result of calling getfiles(dirname, files)
#    extend sizes with the result of calling getsizes(paths)
#
# let size, name be the elements of each tuple in sorted(sizes)
#    print size then name separated by a tab
import sys
import os

def getfiles(dirname,files):
    for name in os.listdir(dirname):
        path = os.path.join(dirname,name)
        if os.path.isdir(path):
            getfiles(path,files)
        elif os.path.isfile(path):
            files.append(path)
    return files

def getsizes(paths):
    sizes = []
    for path in paths:
        sizes.append((os.path.getsize(path), path))
    return sizes

dirs = []

if len(sys.argv) > 1:
    dirs.extend(sys.argv[1:])
else:
    dirs.append(os.getcwd())

sizes = []
for dirname in dirs:
    files = []
    paths = getfiles(dirname,files)
    sizes.extend(getsizes(paths))

for size,name in sorted(sizes):
    print(size,'    ',name)
    
            
        

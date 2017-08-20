import pip
import json


def pip_install(package, version):
    try:
        temp = pip.main(["install", package+'=='+version])
        if temp == 0 :	return True
    	else: return False
    except:
        return False


if __name__ == '__main__':

	JsonObject = json.load(open('dependencies.json'))
	dependencies = JsonObject['Dependencies']
	Logfile = open('log_file','w') #File that logs wether a file has been installed or not.

	for key in dependencies:
		return_bool = pip_install(key,dependencies[key])
		if return_bool == True:
			Logfile.write(key+': Installed\n')
		else:
			Logfile.write(key+': Installation Failed\n')
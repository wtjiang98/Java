
import re

line = "abcdabcebb"
matchobject = re.search(r'(.*b)(+b)', line)
try:
    print(matchobject.groups())
except:
    print('wrong')
import json 

# json 과 유사한 자료구조 : dir
# json.loads(string) --> dict
# json.dumps(dict) --> string

control = {
    "led" : 1,
    "servo" : 45
}

msg = json.dumps(control)
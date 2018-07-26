import json

def say(request, message):
    data = {
            "data": {
                "text": message,
                "zone": -1
            },
            "command": 6
        }
    command(request, data)

def move_to(request, unitId, x, y, z):
    data = {
            "data": {
                "unitId": unitId,
                "groupId": -1,
                "options": 0,
                "toPos": {
                    "x": x,
                    "y": y,
                    "z": z
                }
            },
            "command": 42
        }
    command(request, data)

def command(request, data):
    send = "{}\n".format(json.dumps(data))
    request.sendall(send.encode('utf-8'))
    print("sent: {}".format(send))

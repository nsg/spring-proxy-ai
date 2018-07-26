#!/usr/bin/env python3

import socketserver
import json

import commands

class MyTCPHandler(socketserver.StreamRequestHandler):

    def handle(self):
        while True:
            jdata = self.rfile.readline()
            jd = json.loads(jdata.decode('utf-8'))
            print(" got: {}".format(jd))

            # {'data': {'builder': -1, 'unit': 4734}, 'topic': 5}
            if jd.get('topic') == 5:
                builder = jd['data']['builder']
                unitId = jd['data']['unit']
                # Detect when the commander spawns
                if builder == -1:
                    commands.say(self.request, "Start!")
                    commands.move_to(self.request, unitId, 0, 0, 0)

if __name__ == "__main__":
    HOST, PORT = "0.0.0.0", 8765

    socketserver.TCPServer.allow_reuse_address = True
    with socketserver.TCPServer((HOST, PORT), MyTCPHandler) as server:
        server.serve_forever()

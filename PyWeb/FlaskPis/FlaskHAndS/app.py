from flask import Flask, make_response
from flask import jsonify

app = Flask(__name__)

response = [
    {'a':1,'b':2},
    {'hello':'hello'}
]

@app.route("/")
def hello():
    headers = {"Content-Type": "application/json"}
    return make_response(jsonify(list = response),200,headers)
#    return make_response("hello=world", 200, headers)

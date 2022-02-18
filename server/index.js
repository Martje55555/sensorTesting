const express = require('express');
const cors = require('cors');
const http = require('http')
const app = express();
const server = http.createServer(app);
const {Server} = require("socket.io");

const dht = require('./sensors.js');

const io = new Server(server);

app.use(cors());

app.get('/', (req, res) => {
    console.log('Connection Successful');
});

io.on('connection', (socket) => {
    console.log('socket connection successful')
    console.log(dht.exec());
});

server.listen(3001, () => {
    console.log('listening on *:3001');
    console.log(dht.exec());
});
# Readme

This is a preliminary implementation of a simple TCP client. The client receives from the server a PING every 1-3 seconds, and it replies with a PONG to keep the connection alive. Every 60 seconds, the client sends to a server the result of all the handlers which are running each in a separate thread. The client TCP connection is also spawned into a separate thread.

The client is built on top of QTNetwork, so you will need QT5.

To build the system, you need to execute "cmake ." and then make.

At the moment, unit tests are not available.
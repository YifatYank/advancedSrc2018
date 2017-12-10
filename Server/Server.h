
#ifndef SERVER_H_
#define SERVER_H_

class Server {
	private:
		int port_;
		int server_socket_1_;
		int server_socket_2_;

		void handleClient(int client_socket1, int client_socket2);
		int add(int a, int b);
	public:
		Server(int port);
		void start();
		void stop();
};

#endif /* SERVER_H_ */

#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
using namespace std;
int main(int argc,char *argv[])
{
	fstream openfile;
	for(int i=1;i<argc;i++){
	openfile.open(argv[i],ios::in);
	}
	char buf[1024];
	openfile.read(buf,1024);
	//openfile.close();
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in caddr;
	caddr.sin_family=AF_INET;
	//for(int i=1;i<argc;i++){
	caddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	//}
	caddr.sin_port=htons(8080);
	connect(cfd,(sockaddr*)&caddr,sizeof(caddr));
	send(cfd,buf,sizeof(buf),0);
	//write(cfd,buf,sizeof(buf));
	openfile.close();

	close(cfd);
	return 0;
}

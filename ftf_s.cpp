#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#define PORT 8080
#define IP "127.0.0.1"
#include <fstream>
using namespace std;
int main()
{
//	fstream openfile;
//	openfile.open("2.txt",ios::out);
	char buff[1024]={0};
	int lfc=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in saddr;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(PORT);
	saddr.sin_addr.s_addr=inet_addr(IP);
	bind(lfc,(struct sockaddr*)&saddr,sizeof(saddr));
	listen(lfc,128);
	struct sockaddr_in caddr;
	socklen_t sockelen=sizeof(caddr);
	while(1)
	{
		int c=accept(lfc,(sockaddr*)&caddr,&sockelen); 
		recv(c,buff,1024,0);
		FILE *fp=fopen("3.txt","wb");
		fputs(buff,fp);
		fclose(fp);
		fp=NULL;
		//openfile.write(buff,sizeof(buff));
		//openfile.close();
		//cout<<buff;
	}
	close(lfc);
	return 0;
}

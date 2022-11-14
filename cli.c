#include"head.h"
int main()
{
 	int sock_id;
        char msg[30];
        struct sockaddr_in sa, ca;
        sock_id = socket(AF_INET, SOCK_STREAM, 0);
	printf("%d\n",sock_id);
        if(sock_id >0)
	printf("Socket Created Successfully\n");
        else
        printf("Socket Creation Failed\n");

        sa.sin_family = AF_INET;
        sa.sin_port = htons(8080);
        sa.sin_addr.s_addr = htonl(INADDR_ANY);

        if(connect(sock_id, (struct sockaddr*)&sa, sizeof(sa)) == 0)
        printf("Connected Successfully\n");
        else
        printf("Connection Failed\n");

        printf("Enter the Message : ");
        scanf("%s", msg);
        send(sock_id, msg, sizeof(msg), 0);
	printf("Send.\n");
        
        
	close(sock_id);
	return 0;
}

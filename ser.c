#include"head.h"
int main()
{
	printf("\nServer\n");
	int sid,bid,aid,client_size;
        char msg[100];
        struct sockaddr_in SA,CA;

        sid = socket(AF_INET, SOCK_STREAM, 0);
	printf("%d\n",sid);
        if(sid >0)
	printf("Socket Created Successfully\n");
        else
        printf("Socket Creation Failed\n");

        SA.sin_family = AF_INET;
        SA.sin_port = htons(8080);
        SA.sin_addr.s_addr = htonl(INADDR_ANY);
	
	printf("%d %d\n",sizeof(SA),sizeof(CA));
        client_size = sizeof(CA);

        bid = bind(sid, (struct sockaddr*)&SA, sizeof(SA));
	printf("%d\n",bid);
        if(bid == 0 )
                printf("Binded Successfully\n");
        else
                printf("Bind Failed\n");

        listen(sid, 5);

        aid = accept(sid, (struct sockaddr*)&CA, &client_size);
	printf("%d\n",aid);
        if(aid != -1)
                printf("Accepted Successfully\n");
        else
                printf("Denied.");

        recv(aid, msg, sizeof(msg), 0);
        printf("Message From Client : %s\n", msg);
        send(aid, msg, sizeof(msg), 0);

        close(aid);
	return 0;
}

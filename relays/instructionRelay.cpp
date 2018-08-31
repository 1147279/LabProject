#include <iostream>

using namespace std;

int main()
{
	system("./toFogEdge.sh");
	
	system("./toFogCloud.sh");
	
	system("./toFogEdgeWith10000.sh");
	
	system("./toFogCloudWith10000.sh");
	
	
	system("./toFogEdgeJoin.sh");
	
	system("./toFogCloudJoin.sh");
	
	system("./toFogEdgeJoinWith10000.sh");
	
	system("./toFogCloudJoinWith10000.sh");
	
	
	return 0;
}

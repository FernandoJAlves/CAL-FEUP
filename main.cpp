#include "graphviewer.h"


int main(){
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineEdgeColor("black");
	return 0;
}

#include"mhandler.hpp"

int main(){
	MainHandler *mh = MainHandler::CreateInstance();

	mh->Run();

	MainHandler::DeleteInstance(mh);

	return 0;
}

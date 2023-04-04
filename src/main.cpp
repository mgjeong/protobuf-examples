#include <iostream>
#include <string>

#include "proto/sample1.pb.h"

using namespace std;


int main( int argc, char* argv[])
{
    cout << "protobuf sample" << endl;

    SearchRequest req;
    req.set_query("query1");
    req.set_page_number(1);
    req.set_result_per_page(10);
 
    string bytes;
    req.SerializeToString(&bytes);


    SearchRequest received;
    received.ParseFromString(bytes);
    cout << "query: " << received.query() << endl;
    cout << "page number: " << received.page_number() << endl;
    cout << "result per page: " << received.result_per_page() << endl;

    return 0;
}

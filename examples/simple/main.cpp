#include "../../httpd/qhttpserver.h"
#include "../../lib/resource.h"

#include <QDebug>
#include <QCoreApplication>
#include <QHttpResponseHeader>
#include <QHttpRequestHeader>
#include <QTcpSocket>

class RootResource : public Resource {
    virtual void doGet(const QHttpRequestHeader& header, QTcpSocket* out) {
        qDebug() << "Called RootResource";
        QHttpResponseHeader resp;
        QTextStream stream(out);
        stream << resp.toString() << "\r\n<h1>Test</h1>";
    }
};

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    QHttpServer server;
    RootResource rootResource;
    server.attachResource("/", &rootResource);
    return app.exec();
}
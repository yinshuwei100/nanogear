#include <QDebug>
#include <QCoreApplication>
#include <QHttpResponseHeader>
#include <QHttpRequestHeader>
#include <QTcpSocket>

#include "application.h"
#include "server.h"
#include "httpserver.h"
#include "resource.h"
#include "router.h"

class RootResource : public Resource {
    virtual void handleGet() {
        qDebug() << "Called RootResource::handleGet()";
    }
};

class SimpleApplication : public Application {
    virtual Router* createRoot() {
        Router* r = new Router(context());
        r->attach("/resource", new RootResource());
        return r;
    }
};

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    
    Server* server = new HTTPServer(8080);
    server->attach("/simple", new SimpleApplication());
    server->start();
    
    return app.exec();
}
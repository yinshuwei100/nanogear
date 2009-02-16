/*
 */

#include "server.h"

void Server::attach(const QString& context, Application* app) {
    m_attachedApps[context] = app;
}


int Server::listenPort() const {
    return m_listenPort;
}
void Server::setListenPort(int port) {
    m_listenPort = port;
}

const QHash< QString, Application* >& Server::attachedApps() const {
    return m_attachedApps;
}


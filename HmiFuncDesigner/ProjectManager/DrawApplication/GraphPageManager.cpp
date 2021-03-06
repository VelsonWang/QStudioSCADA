﻿#include "GraphPageManager.h"

GraphPageManager *GraphPageManager::instance_ = Q_NULLPTR;

GraphPageManager::GraphPageManager()
{
}

GraphPageManager *GraphPageManager::getInstance()
{
    if (!instance_) {
        instance_ = new GraphPageManager();
    }
    return instance_;
}

void GraphPageManager::addGraphPage(GraphPage *graphPage)
{
    graphPageList_.append(graphPage);
}

void GraphPageManager::removeGraphPage(GraphPage *graphPage)
{
    graphPageList_.removeAt(graphPageList_.indexOf(graphPage));
}

GraphPage *GraphPageManager::getGraphPageById(const QString &id) const
{
    QListIterator <GraphPage*> iter(graphPageList_);
    GraphPage *graphPage;

    while (iter.hasNext()) {
        graphPage = iter.next();
        if (graphPage->getGraphPageId().contains(id, Qt::CaseInsensitive)) {
            return graphPage;
        }
    }

    return Q_NULLPTR;
}

int GraphPageManager::getIndexByGraphPage(GraphPage *graphPage)
{
    return graphPageList_.indexOf(graphPage);
}

QList<GraphPage*> GraphPageManager::getGraphPageList() const
{
    return graphPageList_;
}

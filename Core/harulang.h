#ifndef HARULANG_H
#define HARULANG_H

#include <QObject>
#include <QXmlStreamReader>
#include <QFile>
#include <QMap>

namespace Core {
class Harulang : public QObject
{
    Q_OBJECT
private:
    // The reader that deals with the XML file
    QXmlStreamReader reader;
    // The current status used in execution, and save files as well
    QMap<QString, QVariant> current_status;
public:
    explicit Harulang(QObject *parent = nullptr);

    /**
     * @brief init: inits the reader QXmlStreamReader object
     * @param file: the file to read from
     */
    void init(QFile file);
    /**
     * @brief next: returns the next primitive tag
     * @param uid: the unique ID of the tag
     * @return the unique ID of the next tag
     */
    int next(int uid);
    /**
     * @brief start_execution: inits current_status for execution
     * @note adds the timestamp and some other meta information
     * @note to the QMap
     */
    void start_execution();
    /**
     * @brief var_set: sets value to variable name
     * @param name
     * @param value
     */
    void var_set(QString name, QVariant value);
    /**
     * @brief var_get: gets the value of variable `name'
     * @param name: the variable to get
     * @return the value of the variable
     * @exceptions throws UndefinedException if `name' is not found
     */
    QVariant var_get(QString name);

signals:

};
}  // namespace Core

#endif // HARULANG_H

//
// Created by lmy on 2022/9/28.
//

#ifndef ULTRASERVER_LOG_H
#define ULTRASERVER_LOG_H

#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdarg>
#include <list>
#include <map>
#include <yaml-cpp/yaml.h>
#include "singleton.h"
#include "mutex.h"
#include "config.h"
#include "env.h"
/**
 * @brief ��ȡroot��־��
 */
#define ULTRA_LOG_ROOT() ultra::LoggerMgr::GetInstance()->getRoot()

/**
 * @brief ��ȡָ�����Ƶ���־��
 */
#define ULTRA_LOG_NAME(name) ultra::LoggerMgr::GetInstance()->getLogger(name)

/**
 * @brief ʹ����ʽ��ʽ����־����level����־д�뵽logger
 * @details ����һ��LogEventWrap���󣬰���������־������־�¼����ڶ�������ʱ������־��д��־�¼�
 * @todo Э��idδʵ�֣���ʱд0
 */
#define ULTRA_LOG_LEVEL(logger , level) \
    if(level <= logger->getLevel()) \
        ultra::LogEventWrap(logger, ultra::LogEvent::ptr(new ultra::LogEvent(logger->getName(), \
            level, __FILE__, __LINE__, ultra::GetElapsedMS() - logger->getCreateTime(), \
            ultra::GetThreadId(), ultra::GetFiberId(), time(0), ultra::GetThreadName()))).getLogEvent()->getSS()

#define ULTRA_LOG_FATAL(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::FATAL)

#define ULTRA_LOG_ALERT(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::ALERT)

#define ULTRA_LOG_CRIT(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::CRIT)

#define ULTRA_LOG_ERROR(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::ERROR)

#define ULTRA_LOG_WARN(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::WARN)

#define ULTRA_LOG_NOTICE(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::NOTICE)

#define ULTRA_LOG_INFO(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::INFO)

#define ULTRA_LOG_DEBUG(logger) ULTRA_LOG_LEVEL(logger, ultra::LogLevel::DEBUG)

/**
 * @brief ʹ��C printf��ʽ����־����level����־д�뵽logger
 * @details ����һ��LogEventWrap���󣬰���������־������־�¼����ڶ�������ʱ������־��д��־�¼�
 * @todo Э��idδʵ�֣���ʱд0
 */
#define ULTRA_LOG_FMT_LEVEL(logger, level, fmt, ...) \
    if(level <= logger->getLevel()) \
        ultra::LogEventWrap(logger, ultra::LogEvent::ptr(new ultra::LogEvent(logger->getName(), \
            level, __FILE__, __LINE__, ultra::GetElapsedMS() - logger->getCreateTime(), \
            ultra::GetThreadId(), ultra::GetFiberId(), time(0), ultra::GetThreadName()))).getLogEvent()->printf(fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_FATAL(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::FATAL, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_ALERT(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::ALERT, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_CRIT(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::CRIT, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_ERROR(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::ERROR, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_WARN(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::WARN, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_NOTICE(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::NOTICE, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_INFO(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::INFO, fmt, __VA_ARGS__)

#define ULTRA_LOG_FMT_DEBUG(logger, fmt, ...) ULTRA_LOG_FMT_LEVEL(logger, ultra::LogLevel::DEBUG, fmt, __VA_ARGS__)
namespace ultra {
    /**
 * @brief ��־����
 */
    class LogLevel {
    public:
        /**
         * @brief ��־����ö�٣��ο�log4cpp
         */
        enum Level {
            /// ���������ϵͳ������
            FATAL = 0,
            /// �����ȼ�������������ݿ�ϵͳ����
            ALERT = 100,
            /// ���ش�������Ӳ�̴���
            CRIT = 200,
            /// ����
            ERROR = 300,
            /// ����
            WARN = 400,
            /// ������ֵ��ע��
            NOTICE = 500,
            /// һ����Ϣ
            INFO = 600,
            /// ������Ϣ
            DEBUG = 700,
            /// δ����
            NOTSET = 800,
        };

        /**
         * @brief ��־����ת�ַ���
         * @param[in] level ��־����
         * @return �ַ�����ʽ����־����
         */
        static const char *ToString(LogLevel::Level level);

        /**
         * @brief �ַ���ת��־����
         * @param[in] str �ַ���
         * @return ��־����
         * @note �����ִ�Сд
         */
        static LogLevel::Level FromString(const std::string &str);
    };

/**
 * @brief ��־�¼�
 */
    class LogEvent {
    public:
        typedef std::shared_ptr<LogEvent> ptr;

        /**
         * @brief ���캯��
         * @param[in] logger_name ��־������
         * @param[in] level ��־����
         * @param[in] file �ļ���
         * @param[in] line �к�
         * @param[in] elapse ����־��������ʼ����ǰ���ۼ����к���
         * @param[in] thead_id �߳�id
         * @param[in] fiber_id Э��id
         * @param[in] time UTCʱ��
         * @param[in] thread_name �߳�����
         */
        LogEvent(const std::string &logger_name, LogLevel::Level level, const char *file, int32_t line, int64_t elapse,
                 uint32_t thread_id, uint64_t fiber_id, time_t time, const std::string &thread_name);

        /**
         * @brief ��ȡ��־����
         */
        LogLevel::Level getLevel() const { return m_level; }

        /**
         * @brief ��ȡ��־����
         */
        std::string getContent() const { return m_ss.str(); }

        /**
         * @brief ��ȡ�ļ���
         */
        std::string getFile() const { return m_file; }

        /**
         * @brief ��ȡ�к�
         */
        int32_t getLine() const { return m_line; }

        /**
         * @brief ��ȡ�ۼ����к�����
         */
        int64_t getElapse() const { return m_elapse; }

        /**
         * @brief ��ȡ�߳�id
         */
        uint32_t getThreadId() const { return m_threadId; }

        /**
         * @brief ��ȡЭ��id
         */
        uint64_t getFiberId() const { return m_fiberId; }

        /**
         * @brief ����ʱ���
         */
        time_t getTime() const { return m_time; }

        /**
         * @brief ��ȡ�߳�����
         */
        const std::string &getThreadName() const { return m_threadName; }

        /**
         * @brief ��ȡ�����ֽ�����������ʽд����־
         */
        std::stringstream &getSS() { return m_ss; }

        /**
         * @brief ��ȡ��־������
         */
        const std::string &getLoggerName() const { return m_loggerName; }

        /**
         * @brief C printf���д����־
         */
        void printf(const char *fmt, ...);

        /**
         * @brief C vprintf���д����־
         */
        void vprintf(const char *fmt, va_list ap);

    private:
        /// ��־����
        LogLevel::Level m_level;
        /// ��־���ݣ�ʹ��stringstream�洢��������ʽд����־
        std::stringstream m_ss;
        /// �ļ���
        const char *m_file = nullptr;
        /// �к�
        int32_t m_line = 0;
        /// ����־��������ʼ����ǰ�ĺ�ʱ
        int64_t m_elapse = 0;
        /// �߳�id
        uint32_t m_threadId = 0;
        /// Э��id
        uint64_t m_fiberId = 0;
        /// UTCʱ���
        time_t m_time;
        /// �߳�����
        std::string m_threadName;
        /// ��־������
        std::string m_loggerName;
    };

/**
 * @brief ��־��ʽ��
 */
    class LogFormatter {
    public:
        typedef std::shared_ptr<LogFormatter> ptr;

        /**
         * @brief ���캯��
         * @param[in] pattern ��ʽģ�壬�ο�sylar��log4cpp
         * @details ģ�����˵����
         * - %%m ��Ϣ
         * - %%p ��־����
         * - %%c ��־������
         * - %%d ����ʱ�䣬����ɸ�һ������ָ��ʱ���ʽ������%%d{%%Y-%%m-%%d %%H:%%M:%%S}������ĸ�ʽ�ַ���C����strftimeһ��
         * - %%r ����־����������ۼ����к�����
         * - %%f �ļ���
         * - %%l �к�
         * - %%t �߳�id
         * - %%F Э��id
         * - %%N �߳�����
         * - %%% �ٷֺ�
         * - %%T �Ʊ��
         * - %%n ����
         *
         * Ĭ�ϸ�ʽ��%%d{%%Y-%%m-%%d %%H:%%M:%%S}%%T%%t%%T%%N%%T%%F%%T[%%p]%%T[%%c]%%T%%f:%%l%%T%%m%%n
         *
         * Ĭ�ϸ�ʽ��������-��-�� ʱ:��:�� [�ۼ����к�����] \\t �߳�id \\t �߳����� \\t Э��id \\t [��־����] \\t [��־������] \\t �ļ���:�к� \\t ��־��Ϣ ���з�
         */
        LogFormatter(const std::string &pattern = "%d{%Y-%m-%d %H:%M:%S} [%rms]%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n");

        /**
         * @brief ��ʼ����������ʽģ�壬��ȡģ����
         */
        void init();

        /**
         * @brief ģ������Ƿ����
         */
        bool isError() const { return m_error; }

        /**
         * @brief ����־�¼����и�ʽ�������ظ�ʽ����־�ı�
         * @param[in] event ��־�¼�
         * @return ��ʽ����־�ַ���
         */
        std::string format(LogEvent::ptr event);

        /**
         * @brief ����־�¼����и�ʽ�������ظ�ʽ����־��
         * @param[in] event ��־�¼�
         * @param[in] os ��־�����
         * @return ��ʽ����־��
         */
        std::ostream &format(std::ostream &os, LogEvent::ptr event);

        /**
         * @brief ��ȡpattern
         */
        std::string getPattern() const { return m_pattern; }

    public:
        /**
         * @brief ��־���ݸ�ʽ�������࣬������������ͬ�ĸ�ʽ����
         */
        class FormatItem {
        public:
            typedef std::shared_ptr<FormatItem> ptr;

            /**
             * @brief ��������
             */
            virtual ~FormatItem() {}

            /**
             * @brief ��ʽ����־�¼�
             */
            virtual void format(std::ostream &os, LogEvent::ptr event) = 0;
        };

    private:
        /// ��־��ʽģ��
        std::string m_pattern;
        /// ������ĸ�ʽģ������
        std::vector<FormatItem::ptr> m_items;
        /// �Ƿ����
        bool m_error = false;
    };

/**
 * @brief ��־����أ�����࣬������������ͬ��LogAppender
 * @details �ο�log4cpp��Appender�Դ�һ��Ĭ�ϵ�LogFormatter���Կؼ�Ĭ�������ʽ
 */
    class LogAppender {
    public:
        typedef std::shared_ptr<LogAppender> ptr;
        typedef Spinlock MutexType;

        /**
         * @brief ���캯��
         * @param[in] default_formatter Ĭ����־��ʽ��
         */
        LogAppender(LogFormatter::ptr default_formatter);

        /**
         * @brief ��������
         */
        virtual ~LogAppender() {}

        /**
         * @brief ������־��ʽ��
         */
        void setFormatter(LogFormatter::ptr val);

        /**
         * @brief ��ȡ��־��ʽ��
         */
        LogFormatter::ptr getFormatter();

        /**
         * @brief д����־
         */
        virtual void log(LogEvent::ptr event) = 0;

        /**
         * @brief ����־���Ŀ�������ת��YAML String
         */
        virtual std::string toYamlString() = 0;

    protected:
        /// Mutex
        MutexType m_mutex;
        /// ��־��ʽ��
        LogFormatter::ptr m_formatter;
        /// Ĭ����־��ʽ��
        LogFormatter::ptr m_defaultFormatter;
    };

/**
 * @brief ���������̨��Appender
 */
    class StdoutLogAppender : public LogAppender {
    public:
        typedef std::shared_ptr<StdoutLogAppender> ptr;

        /**
         * @brief ���캯��
         */
        StdoutLogAppender();

        /**
         * @brief д����־
         */
        void log(LogEvent::ptr event) override;

        /**
         * @brief ����־���Ŀ�������ת��YAML String
         */
        std::string toYamlString() override;
    };

/**
 * @brief ������ļ�
 */
    class FileLogAppender : public LogAppender {
    public:
        typedef std::shared_ptr<FileLogAppender> ptr;

        /**
         * @brief ���캯��
         * @param[in] file ��־�ļ�·��
         */
        FileLogAppender(const std::string &file);

        /**
         * @brief д��־
         */
        void log(LogEvent::ptr event) override;

        /**
         * @brief ���´���־�ļ�
         * @return �ɹ�����true
         */
        bool reopen();

        /**
         * @brief ����־���Ŀ�������ת��YAML String
         */
        std::string toYamlString() override;

    private:
        /// �ļ�·��
        std::string m_filename;
        /// �ļ���
        std::ofstream m_filestream;
        /// �ϴ��ش��ʱ��
        uint64_t m_lastTime = 0;
        /// �ļ��򿪴����ʶ
        bool m_reopenError = false;
    };

/**
 * @brief ��־����
 * @note ��־���಻��root logger
 */
    class Logger {
    public:
        typedef std::shared_ptr<Logger> ptr;
        typedef Spinlock MutexType;

        /**
         * @brief ���캯��
         * @param[in] name ��־������
         */
        Logger(const std::string &name = "default");

        /**
         * @brief ��ȡ��־������
         */
        const std::string &getName() const { return m_name; }

        /**
         * @brief ��ȡ����ʱ��
         */
        const uint64_t &getCreateTime() const { return m_createTime; }

        /**
         * @brief ������־����
         */
        void setLevel(LogLevel::Level level) { m_level = level; }

        /**
         * @brief ��ȡ��־����
         */
        LogLevel::Level getLevel() const { return m_level; }

        /**
         * @brief ���LogAppender
         */
        void addAppender(LogAppender::ptr appender);

        /**
         * @brief ɾ��LogAppender
         */
        void delAppender(LogAppender::ptr appender);

        /**
         * @brief ���LogAppender
         */
        void clearAppenders();

        /**
         * @brief д��־
         */
        void log(LogEvent::ptr event);

        /**
         * @brief ����־��������ת��YAML String
         */
        std::string toYamlString();

    private:
        /// Mutex
        MutexType m_mutex;
        /// ��־������
        std::string m_name;
        /// ��־���ȼ�
        LogLevel::Level m_level;
        /// LogAppender����
        std::list<LogAppender::ptr> m_appenders;
        /// ����ʱ�䣨���룩
        uint64_t m_createTime;
    };

/**
 * @brief ��־�¼���װ��������궨�壬�ڲ�������־�¼�����־��
 */
    class LogEventWrap {
    public:
        /**
         * @brief ���캯��
         * @param[in] logger ��־��
         * @param[in] event ��־�¼�
         */
        LogEventWrap(Logger::ptr logger, LogEvent::ptr event);

        /**
         * @brief ��������
         * @details ��־�¼�������ʱ����־���������
         */
        ~LogEventWrap();

        /**
         * @brief ��ȡ��־�¼�
         */
        LogEvent::ptr getLogEvent() const { return m_event; }

    private:
        /// ��־��
        Logger::ptr m_logger;
        /// ��־�¼�
        LogEvent::ptr m_event;
    };

/**
 * @brief ��־��������
 */
    class LoggerManager {
    public:
        typedef Spinlock MutexType;

        /**
         * @brief ���캯��
         */
        LoggerManager();

        /**
         * @brief ��ʼ������Ҫ�ǽ������ģ��ʵ����־ģ���ʼ��
         */
        void init();

        /**
         * @brief ��ȡָ�����Ƶ���־��
         */
        Logger::ptr getLogger(const std::string &name);

        /**
         * @brief ��ȡroot��־������Ч��getLogger("root")
         */
        Logger::ptr getRoot() { return m_root; }

        /**
         * @brief �����е���־������ת��YAML String
         */
        std::string toYamlString();

    private:
        /// Mutex
        MutexType m_mutex;
        /// ��־������
        std::map<std::string, Logger::ptr> m_loggers;
        /// root��־��
        Logger::ptr m_root;
    };

/// ��־�������൥��
    typedef ultra::Singleton<LoggerManager> LoggerMgr;

}

#endif //ULTRASERVER_LOG_H

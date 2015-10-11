#ifndef _SUSI_KERNEL_LOGGER_H_
#define _SUSI_KERNEL_LOGGER_H_

#define DEFAULT_LOGGER_SOURCE "system"

#include <iostream>
#include <string>


namespace susi {
namespace kernel {

  /**
   * Low level logger for kernel to use
   */
  class Logger {
  public:
    /**
     * Sets output stream
     * @param stream New output stream
     */
    static void setStream(
        std::ostream *stream
    );

    /**
     * Log system info
     * @param msg Message to display
     */
    static void info(
        std::string msg
    );

    /**
     * Log system info
     * @param src Message source
     * @param msg Message to display
     */
    static void info(
        std::string src,
        std::string msg
    );

    /**
     * Log debug info if enabled
     * @param msg Message to display
     */
    static void debug(
        std::string msg
    );

    /**
     * Log debug info if enabled
     * @param src Message source
     * @param msg Message to display
     */
    static void debug(
        std::string src,
        std::string msg
    );

    /**
     * Log system warning
     * @param msg Message to display
     */
    static void warn(
        std::string msg
    );

    /**
     * Log system warning
     * @param src Message source
     * @param msg Message to display
     */
    static void warn(
        std::string src,
        std::string msg
    );

    /**
     * Log system error
     * @param msg Message to display
     */
    static void error(
        std::string msg
    );

    /**
     * Log system error
     * @param src Message source
     * @param msg Message to display
     */
    static void error(
        std::string src,
        std::string msg
    );

  private:
    /** Output stream */
    static std::ostream *ostrm;
    /** If debug messages are enabled */
    static bool debugEnabled;

    /**
     * Post raw message to output
     * @param level Severity level of message
     * @param src Source of message
     * @param msg Message to display
     */
    static void raw(
        std::string level,
        std::string src,
        std::string msg
    );
  }; // class Logger

} // namespace kernel
} // namespace susi
    
#endif

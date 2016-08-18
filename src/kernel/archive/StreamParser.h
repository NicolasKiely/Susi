#ifndef _SUSI_KERNEL_STREAM_PARSER_H_
#define _SUSI_KERNEL_STREAM_PARSER_H_

namespace susi {
namespace util {
  
  /**
   * Represents a state in a bytecode parser
   */
  class StreamState {
    public:
      /**
       * Enter this state from a previous state
       * @param c Character that triggered state change
       */
      virtual void enter(
          int c
      );

      /**
       * Parse input character
       * @param c Input character (passed as integer)
       */
      virtual void parse(
          int c
      );

      /**
       * Returns pointer to next parser state instance
       */
      virtual StreamState *nextState(
          int c
      );
  }


  class TokenStreamState: StreamState {
    public:
      /** Constructor for tokenizer, with default token size */
      TokenStreamState(int defaultSize);

    private:
      /** Token string */
      char *token;

      /** Buffer size for token */
      int bufferSize;

      /** Token string length */
      int tokenLen;
  }
  
} // namespace util
} // namespace susi

#endif

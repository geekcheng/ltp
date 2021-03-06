#ifndef __LTP_PARSER_MODEL_H__
#define __LTP_PARSER_MODEL_H__

#include "featurespace.h"
#include "parameters.h"
#include "options.h"

namespace ltp {
namespace parser {

class Model {
public:
  Model() :
    _dim(-1),
    _num_deprels(-1),
    _num_postags(-1),
    _num_features(-1) {}

  ~Model() {}

  /*
   * get the number of dependency relation types
   *
   *  @return int   the number of dependency relation type
   */
  int num_deprels();

  /*
   * get the number of postag types
   *
   *  @return int   the number of postag type
   */
  int num_postags();

  /*
   * get the number of features
   *
   *  @return int   the number of features
   */
  int num_features();

  /*
   * get the number of dimension
   *
   *  @return int   the number of dimension
   */
  int dim();

private:
  int _num_deprels;
  int _num_postags;
  int _num_features;
  int _dim;

public:
  FeatureSpace      space;
  Parameters        param;

  IndexableSmartMap     postags;
  IndexableSmartMap     deprels;

  /*
   * save the model to the output stream.
   *
   *  @param  out   the output stream
   */
  void save(ostream & out);

  /*
   * load the model from the input stream, return true on
   * success, otherwise false
   *
   *  @param  in    the input stream
   *  @return bool  true on success, otherwise false
   */
  bool load(istream & in);

private:
  void write_uint(ostream & out, unsigned int val) {
    out.write(reinterpret_cast<const char *>(&val), sizeof(unsigned int));
  }

  unsigned int read_uint(istream & in) {
    char p[4];
    in.read(reinterpret_cast<char*>(p), sizeof(unsigned int));
    return *reinterpret_cast<const unsigned int*>(p);
  }
};    //  end for class model

}     //  end for namespace parser
}     //  end for namespace ltp
#endif  //  end for __LTP_PARSER_MODEL_H__

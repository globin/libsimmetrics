include_directories("${libsimmetrics_SOURCE_DIR}/include")

SET(SOURCES
  block_distance.cpp
  cosine_similarity.cpp
  cost.cpp
  dice_similarity.cpp
  double_metaphone.cpp
  euclidean_distance.cpp
  jaccard_similarity.cpp
  jaro.cpp
  jaro_winkler.cpp
  levenshtein.cpp
  matching_coefficient.cpp
  metaphone.cpp
  monge_elkan.cpp
  needleman_wunch.cpp
  overlap_coefficient.cpp
  qgrams_distance.cpp
  smith_waterman.cpp
  smith_waterman_gotoh.cpp
  soundex.cpp
  simmetrics.cpp
  tokenizer.cpp
  util.cpp
)

add_library(simmetrics ${SOURCES})
install(TARGETS simmetrics DESTINATION lib)
install(DIRECTORY ../include/ DESTINATION include/simmetrics FILES_MATCHING PATTERN *.h)

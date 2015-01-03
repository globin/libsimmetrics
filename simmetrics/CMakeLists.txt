include_directories("${libsimmetrics_SOURCE_DIR}/include")

SET(SOURCES
  block_distance.cpp
  cosine_similarity.cpp
  cost.c
  dice_similarity.cpp
  double_metaphone.c
  euclidean_distance.cpp
  jaccard_similarity.cpp
  jaro.c
  jaro_winkler.c
  levenshtein.cpp
  matching_coefficient.cpp
  metaphone.c
  monge_elkan.cpp
  needleman_wunch.c
  overlap_coefficient.cpp
  qgrams_distance.cpp
  smith_waterman.c
  smith_waterman_gotoh.c
  soundex.c
  simmetrics.c
  tokenizer.cpp
  util.c
)

add_library(simmetrics ${SOURCES})
install(TARGETS simmetrics DESTINATION lib)
install(DIRECTORY ../include/ DESTINATION include/simmetrics FILES_MATCHING PATTERN *.h)

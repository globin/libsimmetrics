include_directories("${libsimmetrics_SOURCE_DIR}/include")

SET(SOURCES
  block_distance.c
  cosine_similarity.c
  cost.c
  dice_similarity.c
  double_metaphone.c
  euclidean_distance.c
  jaccard_similarity.c
  jaro.c
  jaro_winkler.c
  levenshtein.c
  matching_coefficient.c
  metaphone.c
  monge_elkan.c
  needleman_wunch.c
  overlap_coefficient.c
  qgrams_distance.c
  smith_waterman.c
  smith_waterman_gotoh.c
  soundex.c
  simmetrics.c
  tokenizer.c
  util.c
)

add_library(simmetrics ${SOURCES})

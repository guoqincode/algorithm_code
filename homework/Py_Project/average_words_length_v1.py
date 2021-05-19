# 计算字符串中单词平均长度
# 代码



# 测试
sentence1 = "Hi all, my name is Tom...I am originally from Australia."
sentence2 = "This is the string whose words we would like to count. " \
           "This string contains some repeated words, " \
           "as well as some unique words. " \
           "It contains punctuation, " \
           "and it contains words that are capitalized in different ways. " \
           "If the method we write runs correctly, " \
           "it will count 4 instances of the word 'it', " \
           "3 instances of the word 'this', " \
           "and 3 instances of the word 'count'."
print("第一个字符串单词平均长度为：",average_word_length(sentence1))
print("第一个字符串单词平均长度为：",average_word_length(sentence2))
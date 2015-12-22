class LineAnalyzer
  attr_reader :highest_wf_count
  attr_reader :highest_wf_words
  attr_reader :content
  attr_reader :line_number

  def initialize(content, line_number)
    @highest_wf_count = 0 
    @highest_wf_words = Array.new()
    @content = content
    @line_number = line_number
    calculate_word_frequency()
  end

  def calculate_word_frequency()
    words = content.split()
    frequency = Hash.new(0)
    words.each { |word| frequency[word.downcase] += 1 } 
    @highest_wf_count = frequency.max_by{ |k, v| v }[1] 
    frequency.each do |k, v|
      if v === @highest_wf_count 
        @highest_wf_words.push(k)
      end  
    end
  end

end

#  Implement a class called Solution. 
class Solution

  attr_reader :analyzers, :highest_count_across_lines, :highest_count_words_across_lines 

  def initialize()
    @analyzers = Array.new()
  end
  
  def analyze_file()
    lines = IO.foreach('test.txt')
    lines.each_with_index { |line, index| @analyzers.push(LineAnalyzer.new(line, index)) }
  end
  
  def calculate_line_with_highest_frequency()
    @highest_count_words_across_lines = Array.new()
    @analyzers.max_by do |analyzer| 
      @highest_count_across_lines = analyzer.highest_wf_count
    end  
   
    @analyzers.each do |analyzer| 
      if analyzer.highest_wf_count === @highest_count_across_lines
        @highest_count_words_across_lines.push(analyzer)
      end
    end
  end

  def print_highest_word_frequency_across_lines()
    puts "The following words have the highest word frequency per line:" 
    @highest_count_words_across_lines.each do |analyzer|
      puts "#{analyzer.highest_wf_words} (appears in line \##{analyzer.line_number + 1})" 
    end 
  end
  
end

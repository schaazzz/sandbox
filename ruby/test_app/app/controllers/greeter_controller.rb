class GreeterController < ApplicationController
  def hello
    random_words = ['test', 'best', 'chest', 'crest', 'rest']
    @name = random_words.sample
    @time = Time.now
    @times_displayed ||= 0
    @times_displayed += 1
  end
  def goodbye
  end
end

import speech_recognition as sr


r = sr.Recognizer()
while True:
    with sr.Microphone() as source:
        print('speak anything: ')
        audio = r.listen(source,phrase_time_limit = 4)
        try:
            text = r.recognize_google(audio)
            print(text)

        except:
            pass

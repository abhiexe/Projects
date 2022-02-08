# Cricinfo Extracter

1. Name of the Project --> Cricinfo Extracter (Cricinfo 2019 WorldCup Data Extractor)


2. Purpose --> The purpose of the project is to extract the information of Worlcup 2019 from Cricinfo snd present that info in the form of excel and pdf scorecards.
           --> The real purpose of the project is to learn how to extract the information from a website and get experience with it.
           
3. Reason --> A very good reason for me to make this project is I enjoyed making it, It was a great fun activity for me.


4.Programming Language --> JavaSript

5. The dependencies used by me while making this project are:-
        i). minimist
        ii). axios
        iii). jsdom
        iv). excel4node
        v). pdf-lib
        vi). fs -> this library is pre-installed in node
        vii).pdf -> to give the pathname of files


6. Activity --> The tasks performed while making the project are
        i). Read data from the source: Cricinfo Worlcup 2019 (using the axios library)
        ii). Process the data we read from the website: Get all the teams( using the jsdom library)
        iii). Change the information extracted (Array Manipulation)
        iv). Write processed data in excel (Match result per team in their own sheet)
        v). Create folder: one for each team
        vi). Write files: PDF files for scorecard of each match in the relevant folder

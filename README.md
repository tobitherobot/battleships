# Schiffe versenken a.k.a. Battleships
    Team Sardone(TM):
        Tobias Baumann, Frank Sadoine, David Poland

# Einleitung
    Dieses Projekt soll das Brettspiel Schiffe versenken in C++ umsetzen.
    Zusätzlich wurden noch andere Features hinzugefügt, wie:
        - Steurung des Programs über Textbefehle
        - Spielanzeige und Menüführung über Konsole
        - Einzel- und Zweispielermodus
        - Korrektheit der Eingaben wird überprüft
        - Simple KI
        - KI vs KI Modus

    Wichtige Informationen:
        - Die Main.cpp Datei muss kompiliert werden um das Programm zu starten.
        - Die bedeutung der characters auf dem Spielfeld ist wie folgt:
            ~ -> Wasser
            M -> Früheres Ziel ohne Treffer
            O -> Schiff
            X -> Getroffenes Schiff

# Spielablauf
    1. Menü mit Modusauswahl wird angezeigt.
    2. Auswahl des gewünschten Punktes durch eingeben in Konsole.
    2.1 [1] Einzelspielermodus, fordert zum Eingeben der Schiffpositionen auf.
        2.1.1 Nachdem alle Schiffe den Regeln entsprechend platziert wurden startet das Spiel gegen den KI Gegner. Der erste Zug wird zufällig übergeben.
        2.1.2 Oben wird das Feld vom Gegner angezeigt, unten das eigene Feld. Durch Eingabe einer Koordinate kann man auf das gegnerische Feld schiessen.
        2.1.3 Wenn ein Schiff versenkt wird kommt eine entsprechende Meldung in der Konsole.
        2.1.4 Wenn auf einem Feld alle Schiffe versenkt wurden, wird der Sieger bestimmt und ausgegeben.
        2.1.5 Im Anschluss kann man das Programm beenden oder zurück ins Startmenü gehen
    2.2 [2] Zweispielermodus, fordert erst Spieler 1 zum eingeben auf, dann Spieler 2.
        2.2.1 Nachdem alle Schiffe den Regeln entsprechend platziert wurden startet das Spiel gegen den anderen Spieler. Der erste Zug wird zufällig übergeben.
        2.2.2 Oben wird das Feld vom Gegner angezeigt, unten das eigene Feld. Durch Eingabe einer Koordinate kann man auf das gegnerische Feld schiessen.
        2.2.3 Danach hat der andere Spieler die selbe Option.
        2.2.4 Wenn auf einem Feld alle Schiffe versenkt wurden, wird der Sieger bestimmt und ausgegeben.
        2.2.5 Im Anschluss kann man das Programm beenden oder zurück ins Startmenü gehen
    2.3 [0] KI vs KI Modus, zwei KIs spielen gegeneinander.
        2.3.1 Nach dem schnellen Spielablauf ist das Endergebnis zu sehen und der Ablauf kann durch hochscrollen überprüft werden.
        2.3.2 Da die KI ausschließlich zufällig schießt sind im Ergebnis oft sehr viele M enthalten.
        2.3.3 Im Anschluss kann man das Programm beenden oder zurück ins Startmenü gehen
    2.4 [quit] Beendet das Programm.

package utils;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Logger {
	private final static String fichierLogs = "logs.txt";
	private final static Path filePath = new File(fichierLogs).toPath();
	private final String id;
	private final char delimAV;
	private final char delimAP;
	private final String prefix;

	/**
	 * Constructeur pour renseigner l'identité choisie avec les délimiteurs "[" et
	 * "]"
	 * 
	 * @param id Le nom choisi pour l'identité
	 */
	public Logger(String id) {
		this.id = id;
		if (!id.equals("")) {
			this.delimAV = '[';
			this.delimAP = ']';
			this.prefix = this.delimAV + " " + this.id + " " + delimAP + " ";
		}
		else {
			this.delimAV = ' ';
			this.delimAP = ' ';
			this.prefix = "";
		}
	}

	/**
	 * Constructeur pour renseigner l'identité choisie avec des délimiteurs choisis
	 * (identiques)
	 * 
	 * @param id    Le nom choisi pour l'identité
	 * @param delim Le délimiteur qui sera au début et à la fin
	 */
	public Logger(String id, char delim) {
		this.id = id;
		this.delimAV = this.delimAP = delim;
		this.prefix = this.delimAV + " " + this.id + " " + delimAP + " ";
	}

	/**
	 * Constructeur pour renseigner l'identité choisie avec des délimiteurs choisis
	 * 
	 * @param id      Le nom choisi pour l'identité
	 * @param delimAV Le délimiteur de début (donc avant le message)
	 * @param delimAP Le délimiteur de fin (donc après le message)
	 */
	public Logger(String id, char delimAV, char delimAP) {
		this.id = id;
		this.delimAV = delimAV;
		this.delimAP = delimAP;
		this.prefix = this.delimAV + " " + this.id + " " + delimAP + " ";
	}

	/**
	 * Permet d'afficher un message préfixé
	 * (selon la configuration choisie à la construction).
	 * 
	 * @param message Le message à afficher sur la sortie standard
	 */
	public void printInfo(String message, String color) {
		System.err.println(color + prefix + message + ConsoleColors.RESET);
		logsFile("INFO  " + prefix + message + "\n");
	}
	public void printInfo(String message) { printInfo(message, ConsoleColors.RESET); }

	public void printError(String message) {
		System.err.println(ConsoleColors.RED_BRIGHT + prefix + message + ConsoleColors.RESET);
		logsFile("ERROR " + prefix + message + "\n");
	}

	public void printWarning(String message) {
		System.err.println(ConsoleColors.ORANGE + prefix + message + ConsoleColors.RESET);
		logsFile("WARN  " + prefix + message + "\n");
	}

	private void logsFile(String message) {
		try {
			if (!new java.io.File(fichierLogs).exists()) {
				java.nio.file.Files.write(filePath, "".getBytes());
			}
			Files.write(
				filePath,
				(
					new SimpleDateFormat("yyyy/MM/dd H:m:s").format(new Date())
					+ " -> "
					+ message
				).getBytes(),
				StandardOpenOption.APPEND
			);
		} catch (IOException e) {
			System.err.println(e);
		}
	}
	public static void resetLogsFile() {
		try {
			if (new java.io.File(fichierLogs).exists()) {
				java.nio.file.Files.write(filePath, "\n".getBytes());
			}
		} catch (IOException e) {
			System.err.println(e);
		}
	}

	/**
	 * Redéfinition du toString pour indiquer la configuration actuelle
	 * 
	 * @return La configuration actuelle du Logger
	 */
	@Override
	public String toString() {
		String configuration = "\nConfiguration actuelle :\n";
		configuration += "\tIdentité         = " + this.id + "\n";
		configuration += "\tDélimiteur avant = " + this.delimAV + "\n";
		configuration += "\tDélimiteur après = " + this.delimAP + "\n";
		configuration += "\tPréfix résultant = " + this.prefix + "\n";
		return configuration;
	}

	public String getId() {
		return this.id;
	}

	public String getPrefix() {
		return this.prefix;
	}
}

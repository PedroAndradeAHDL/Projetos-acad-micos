package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Samurai extends Four_Classes {
	
	private String rank;
	private String clan;
	private boolean bushido;
	
	private Edo_Society daimyoLord;

	public String getRank() {
		return rank;
	}

	public void setRank(String rank) {
		this.rank = rank;
	}

	public String getClan() {
		return clan;
	}

	public void setClan(String clan) {
		this.clan = clan;
	}

	public boolean isBushido() {
		return bushido;
	}

	public void setBushido(boolean bushido) {
		this.bushido = bushido;
	}

	public Edo_Society getDaimyoLord() {
		return daimyoLord;
	}

	public void setDaimyoLord(Edo_Society daimyoLord) {
		this.daimyoLord = daimyoLord;
	}

	
}

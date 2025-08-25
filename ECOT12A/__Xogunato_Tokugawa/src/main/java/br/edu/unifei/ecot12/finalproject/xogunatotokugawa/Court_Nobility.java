package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Court_Nobility extends Edo_Society {
	
	private String relationshipEmperor;
	private String residence;
	
	private Constructors royalConstructors = new RoyalConstructors();
	private Constructors religiousConstructors = new ReligiousConstructors();
	private Constructors botanicals = new Botanicals();

	public String getRelationshipEmperor() {
		return relationshipEmperor;
	}
	public void setRelationshipEmperor(String relationshipEmperor) {
		this.relationshipEmperor = relationshipEmperor;
	}
	public String getResidence() {
		return residence;
	}
	public void setResidence(String residence) {
		this.residence = residence;
	}
	public Constructors getRoyalConstructors() {
		return royalConstructors;
	}
	public void setRoyalConstructors(Constructors royalConstructors) {
		this.royalConstructors = royalConstructors;
	}
	public Constructors getReligiousConstructors() {
		return religiousConstructors;
	}
	public void setReligiousConstructors(Constructors religiousConstructors) {
		this.religiousConstructors = religiousConstructors;
	}
	public Constructors getBotanicals() {
		return botanicals;
	}
	public void setBotanicals(Constructors botanicals) {
		this.botanicals = botanicals;
	}
	

}

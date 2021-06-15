package com.grammer.lintCode;
/*
* https://www.lintcode.com/problem/747/solution/33163
* 修饰器模式
* */
public class CoffeeMaker {

    public Coffee makeCoffee(CoffeePack pack) {
        // write your code here
        Coffee ans = new SimpleCoffee();
        for(int i = 0, n = pack.getNeededMilk(); i < n; i++){
            ans = new WithMilk(ans);
        }
        for(int i = 0, n = pack.getNeededSugar(); i < n; i++){
            ans = new WithSugar(ans);
        }
        //System.out.println("Cost for this coffee is: " + ans.getCost());
        //System.out.println("Ingredients for this coffee is: " + ans.getIngredients());
        return ans;
    }
}

class CoffeePack {
    private int neededMilk;
    private int neededSugar;

    public CoffeePack(int neededMilk, int neededSugar) {
        this.neededMilk = neededMilk;
        this.neededSugar = neededSugar;
    }

    public int getNeededMilk() {
        return neededMilk;
    }

    public int getNeededSugar() {
        return neededSugar;
    }
}

interface Coffee {
    public double getCost();
    public String getIngredients();
}

class SimpleCoffee implements Coffee {

    @Override
    public double getCost() {
        // TODO Auto-generated method stub
        return 2;
    }

    @Override
    public String getIngredients() {
        // TODO Auto-generated method stub
        return "Plain Coffee";
    }

}

abstract class CoffeeDecorator implements Coffee {
    protected final Coffee decoratedCoffee;

    public CoffeeDecorator(Coffee coffee) {
        this.decoratedCoffee = coffee;
    }

    public double getCost() {
        return decoratedCoffee.getCost();
    }

    public String getIngredients() {
        return decoratedCoffee.getIngredients();
    }
}

class WithMilk extends CoffeeDecorator {

    public WithMilk(Coffee coffee) {
        super(coffee);
    }

    public double getCost() {
        return super.getCost() + 0.5;
    }

    public String getIngredients() {
        return super.getIngredients() + ", Milk";
    }
}

class WithSugar extends CoffeeDecorator {

    public WithSugar(Coffee coffee) {
        super(coffee);
    }

    public double getCost() {
        return super.getCost() + 0.5;
    }

    public String getIngredients() {
        return super.getIngredients() + ", Sugar";
    }
}